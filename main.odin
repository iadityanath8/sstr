package a

import "ffi"

import "core:fmt"

main :: proc(){
    a := ffi.new(cstring("Meow"))
    defer ffi.free(a)
    fmt.println(a)
}