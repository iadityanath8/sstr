package sstr

import "core:c"
import "core:fmt"

foreign import s "../libsstr.a"

/** Semantic difference  **/ 
sstr :: distinct cstring

@(link_prefix = "sstr_")
foreign s{
    new             :: proc(a:cstring) -> sstr ---
    len             :: proc(a:sstr) -> c.size_t ---
    cap             :: proc(a:sstr) -> c.size_t ---
    sstr_reallocate :: proc(a :[^]c.char) -> [^]c.char---
    append_char     :: proc(a:^sstr,b:c.char) ---
    append_str      :: proc(a:^sstr,b:cstring) ---
    append_sstr     :: proc(a:^sstr, b:cstring) ---
    cat             :: proc(a:sstr, b:sstr) -> sstr ---
    dup             :: proc(a:sstr) -> sstr ---;
    find            :: proc(a:sstr, b:rune) -> bool ---
    eq              :: proc(a:sstr,b:cstring) -> bool ---
    at              :: proc(a:sstr, idx: c.ssize_t) -> rune ---
    split           :: proc(a:sstr,d:rune,page_len:^c.size_t) -> [^]sstr ---
    free            :: proc(a:sstr) ---
    freeList        :: proc(p:[^]sstr, page_len: c.size_t) ---
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
