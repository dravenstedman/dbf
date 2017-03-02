DBF 1.0

Designed and implemented by Draven Stedman

Pretty much a fork of Brainfuck designed to be very easily implementable and absolutely painful for the programmer to use.

Uses 7 two-byte "commands":

FF - moves data pointer forward 1
BB - backward 1

II - increment data at pointer by 1
DD - decrement 1

OO - output data

J# - where # is number of commands to jump, jump that many commands forward unconditionally

---

Changelog:
v0.5 - accidentally deleted due to Draven being fucking stupid
v1.0 - reimplementation began with Python

To-Do:
v1.5 - reimplement in Pascal and/or C++
v1.6 - add unconditional jump backwards
v2.0 - add conditional jumps
