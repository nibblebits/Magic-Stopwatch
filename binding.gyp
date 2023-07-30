{
	"targets": [
		{
			"target_name": "addon",
			"sources": ["src/cpp/addon.cpp"],
			"include_dirs": ["<!(node -e \"require('nan')\")"]
		}
	]
}