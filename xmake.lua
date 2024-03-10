set_project("Project name")
set_version("1.0.0")

set_languages("c++latest")

add_rules("mode.debug", "mode.release")

-- Set all possible warnings
set_warnings("all", "error")

-- Setup for debug symbols and optimization
if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
else
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
end

-- Function to add platform-specific flags
function add_platform_specific_flags()
    if is_plat("windows") then
        add_cxxflags("/EHsc")
    else
        -- Add flags for e.g. linux here
    end
end

target("test_target_name")
    set_kind("binary")
    add_files("src/*.cppm")
    add_platform_specific_flags()
target_end()

-- Define the test dependency
add_requires("gtest", {configs = {main = false, gmock = true}})

-- Iterate over test files and create test targets
for _, file in ipairs(os.files("tests/test_*.cpp")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        add_packages("gtest")
        set_default(false)
        add_files(file)
        add_tests("default")
        add_platform_specific_flags()
end