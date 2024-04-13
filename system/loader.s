.global _start

.section .text
_start:
    # 设置栈指针
    mov $0x7c00, %esp

    # 从磁盘读取内核到内存的地址 0x10000 处
    mov $0x02, %ah         # 功能号：读取扇区
    mov $0x01, %al         # 要读取的扇区数
    mov $0x1000, %bx       # 目标内存地址
    mov $0x00, %ch         # 柱面号
    mov $0x02, %cl         # 起始扇区号
    mov $0x00, %dh         # 磁头号
    int $0x13              # BIOS 中断：磁盘操作

    .exturn main
    .space 2*1024*1024