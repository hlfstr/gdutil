#ifndef _GSETTINGS_H_
#define _GSETTINGS_H_

#include <ConfigFile.hpp>
#include <Godot.hpp>
#include <InputEventKey.hpp>
#include <InputMap.hpp>
#include <Node.hpp>
#include <OS.hpp>

#include <iostream>

#include <gdregistry/gdregistry.hpp>
#include <gdutil.hpp>

namespace godot {
class GSettings : public Node {
	GDCLASS(GSettings, Node);

public:
	void _ready();

	static GSettings *instance();

	Variant get(String section, String key, Variant dfault = Variant());
	void set(String section, String key, Variant value);
	void setDefault(Dictionary dict);
	Variant getFilename();

	//keymap
	void setDefaultKeymap(Dictionary dict);
	void setKeymap(String name);
	Array getKeyMapNames() const;
	Dictionary getKeymap(String name) const;
	Dictionary getCurrentKeymap() const;
	void setKey(String name, Variant value);

protected:
	ConfigFile *_file;

	String _fileName;
	String _fullPath;

	Dictionary _defaultSettings;
	Dictionary _activeSettings;

	Dictionary _keymaps;

	Error _load();
	void _save();

	void _setInput(String action, int key);

private:
	static GSettings *_instance;

	const String _sKey = "ginput";
};
} // namespace godot

#endif