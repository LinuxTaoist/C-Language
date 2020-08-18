version    : V1.1
date       : 2020-08-18
description: 参考linux内核通用链表写的C语言链表。由于链表中数据域会限制双链表的通用性，
             故在通用链表中去除数据域。在使用时新建一个结构体并添加封装的链表成员，利
             用提供的通用API使结构体链表成员搭建成一个循环双链表，即可通过双链表操作实
             现链表寻址。然后通过链表成员，寻址到用户搭建的结构体首地址：
             #define list_entry(ptr, type, member) \
             ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))
             挺好用的一种通用性数据结构设计。
             
