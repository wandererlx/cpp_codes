package(default_visibility = ["//visibility:public"])

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
	name = "iterator_pattern_test",
	srcs = [
	       "iterator_pattern_test.cc",
	],
	copts = [],
	deps = [
		"//menuitem:diner_menu",
		"//menuitem:pancake_house_menu",
		"//waitress:waitress",
	],
)
