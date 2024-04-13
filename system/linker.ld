ENTRY(_start)

SECTIONS {
    /* 内核起始地址 */
    . = 0x10000;

    /* .text 段，存放代码 */
    .text : {
        *(.text)
    }

    /* .rodata 段，存放只读数据 */
    .rodata : {
        *(.rodata)
    }

    /* .data 段，存放初始化的数据 */
    .data : {
        *(.data)
    }

    /* .bss 段，存放未初始化的数据 */
    .bss : {
        *(.bss)
    }

    /* 内核结束地址 */
    . = 0x7FFF;
}