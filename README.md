# Nano Cpp Themes

Personal library of C++ themes for the nano text editor, nano is my go-to place to quickly solve competitive programming problems or code lookups.

This repo contains:
Ten GNU nano colour themes for C++, with previews rendered from the same rules the files contain.

- `previews/index.html` interactive gallery (open in a browser); `previews/*.png` one image per theme
- `themes/*.nanorc` one complete theme per file
- `sample/example.cpp` the file every preview uses

| Theme | File | Terminal background | Terminal foreground |
|---|---|---|---|
| Dracula | `dracula.nanorc` | `#282a36` | `#f8f8f2` |
| Tokyo Night | `tokyo-night.nanorc` | `#1a1b26` | `#c0caf5` |
| Catppuccin Mocha | `catppuccin.nanorc` | `#1e1e2e` | `#cdd6f4` |
| Nord | `nord.nanorc` | `#2e3440` | `#d8dee9` |
| Gruvbox Dark | `gruvbox.nanorc` | `#282828` | `#ebdbb2` |
| Cyberpunk | `cyberpunk.nanorc` | `#0d0221` | `#e0f7ff` |
| Monokai Pro | `monokai.nanorc` | `#2d2a2e` | `#fcfcfa` |
| One Dark | `onedark.nanorc` | `#282c34` | `#abb2bf` |
| Matrix | `matrix.nanorc` | `#010a03` | `#9bf5b0` |
| Minimal Dark | `minimal-dark.nanorc` | `#1c1c1e` | `#d4d4d8` |

nano cannot paint the terminal background or the default text colour. Set your terminal profile background and foreground to the hexes above for the look in the previews; the highlight colours stay readable on any dark background.

## Requirements
nano 7.2 or newer (tested on 7.2) and a 256-colour terminal (`echo $TERM` should print `xterm-256color` or similar). The files use only nano's named colours (`mauve`, `sky`, `sage`, ...) because nano 7.2 rejects numeric and `#rrggbb` colours. `black` and `lightwhite` come from your terminal's own palette.

## Preview a theme without changing your config
`--rcfile` makes nano read only that file, ignoring `/etc/nanorc` and `~/.nanorc`:

    nano --rcfile="$HOME/nano-cpp-themes/themes/nord.nanorc" sample/example.cpp

## Install
    mkdir -p ~/.nano/themes
    cp themes/*.nanorc ~/.nano/themes/

Add to `~/.nanorc` (one theme include at a time):

    include "~/.nano/themes/dracula.nanorc"
    set linenumbers
    set tabsize 4
    set tabstospaces
    set autoindent

## Switch themes
Change the `include` line, or add this to `~/.bashrc` / `~/.zshrc`:

    nanotheme() { sed -i "s#^include \"~/.nano/themes/.*\"#include \"~/.nano/themes/$1.nanorc\"#" ~/.nanorc; }

Then run `nanotheme tokyo-night`.

## Make sure C++ highlighting is on
Each theme defines a syntax named `cpp-<theme>` for `.cc .cpp .cxx .hh .hpp .hxx .h .ino`. Open a `.cpp` file: if keywords, strings and comments are coloured, you are done. If you see your distro's stock colours instead, the system C++ syntax is winning. Either force the theme's syntax:

    nano -Y cpp-dracula file.cpp          # or: alias nano='nano -Y cpp-dracula'

or comment out the `include "/usr/share/nano/*.nanorc"` line in `/etc/nanorc` (needs sudo).

## How it highlights
Rules run top to bottom and later rules override earlier ones: operators, namespaces (`std::`), function calls, punctuation, PascalCase class names, constants and macros, types, standard library names, keywords, numbers, preprocessor lines and include paths, strings and chars, escapes, `//` and `/* */` comments, then TODO/FIXME tags inside comments. Trailing whitespace gets a red background.
