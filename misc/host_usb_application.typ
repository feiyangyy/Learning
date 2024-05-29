#import "@preview/pintorita:0.1.1"

// #set page(height: auto, width: auto, fill: white, margin: 2em)
// #set text(fill: white)

#show raw.where(lang: "pintora"): it => pintorita.render(it.text)

== USB 协议栈的星（树）形结构
1. 每个USB总线都有一个根集线器，一个电脑或者host设备上可以有多个根集线器
  - 每个总线都有编号，从0开始 对应于 libusb_get_bus_number
2. 从根集线器开始，可以挂在设备和普通集线器（Hub），USB协议规定  至多只能有5个hub级联，也就是最后一个hub必须挂载设备，从而USB拓扑的深度是7（算上最后一级hub的设备）
  - 虽然USB总线拓扑看起来像树形结构，但是其本质上是一个中心的星型结构。比如我们常见的hub，他至多可以有8个端口，然后厂家会拿其中一个端口做成USB公头，使其能和其他hub连接
  - 端口编号为[1,8], 0号端口要么用于特殊目的，要么表示一些错误或不可用
3. 设备的定位
  - 像linux 对usb设备的编号一样，通过 总线编号+端口号列表，可以唯一确定一个设备在总线中的拓扑位置
  - 以linux的编号为例，其规则是:`[bus_number]-[port_list]`, port_list的表示为`a.b.c.d ...`（...表可能更多的意思），其中a b c d 都是1-8的数
    - 比如 `1-2.3.3` 就表示挂在1号bus下的第2个端口（是一个集线器）的第3个端口（仍然是一个集线器）的第三个端口上，形如
    ```
    root_hub_1 (bus number 1)
    |---- (port 1...)
    |---- hub  (port 3)
          |----- (port 1...)
          |----- (port 2...)
          |----- hub
                  | -------
                  | -------
                  | ------- device
    ```
    - 对于这个例子，如果调用libusb_get_port_numbers 其port_numbers 传出参数就是[2,3,3]
== 基本步骤

1. 调用libusb_get_device_list 获取设备列表
2. for dev in devices,
  - 执行libusb_get_device_descriptor 获取描述符
  - 