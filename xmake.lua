add_rules("mode.debug", "mode.release")

includes("xf_utils/xmake.lua")

function add_xf_sys() 
    add_includedirs("src")
    add_files("src/*.c")
end

target("xf_sys")
    set_kind("binary")
    add_cflags("-Wall")
    add_cflags("-std=gnu99 -O0 -g")
    add_files("example/*.c")
    add_includedirs("example")
    add_xf_sys()
    add_xf_utils("xf_utils")