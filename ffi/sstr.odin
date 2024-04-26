package main

import "core:c"
import "core:fmt"

foreign import s "../libsstr.a"


@(link_prefix = "sstr_")
foreign s{
    new :: proc(a : cstring) -> cstring ---
    len :: proc(a: cstring) -> c.size_t ---
    cap :: proc(a :cstring) -> c.size_t ---
    // sstr_reallocate :: proc(a :[^]c.char) -> [^]c.char---
    append_char :: proc(a:^cstring,b: c.char) ---
    append_str :: proc(a:^cstring,b:cstring) ---
    append_sstr :: proc(a:^cstring, b:cstring) ---
    cat :: proc(a:cstring, b:cstring) -> cstring ---
    dup :: proc(a:cstring) -> cstring ---;
    find :: proc(a: cstring, b:rune) -> bool ---
    eq :: proc(a: cstring,b:cstring) -> bool ---
    at :: proc(a:cstring, idx: c.ssize_t) -> rune ---
    split :: proc(a:cstring,d:rune,page_len:^c.size_t) -> [^]cstring ---
    free :: proc(a:cstring) ---
    freeList :: proc(p:[^]cstring, page_len: c.size_t) ---
}

s_free :: proc{free,freeList}

main :: proc(){
    c := new(cstring("MEOW is my billu in herer"))
    defer s_free(c)
    page_len :uint= 0
    p := split(c,' ',&page_len)
    defer s_free(p,page_len)

    fmt.println(p[0])
}
