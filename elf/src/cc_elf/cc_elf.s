.section .text
global ctrampo
ctrampo:
  mov eax, [esp + 4]
  mov ecx, [esp + 8]
  mov edx, [esp + 12]
  