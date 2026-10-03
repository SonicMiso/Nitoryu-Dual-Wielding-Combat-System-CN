# Nitoryu CN

这是 [Nitoryu: Dual Wielding Combat System](https://steamcommunity.com/sharedfiles/filedetails/?id=3812165089) 的中文语言附属 Mod。

## 原理

Nitoryu 的语言文件由 `Nitoryu.dll` 按自身所在目录读取，因此仅在汉化 Mod 自己的 `lang/zh.ini` 中放置文件不会生效。

本 Mod 使用 RE_Kenshi 的 `PreloadPlugins` 机制，在 Nitoryu.dll 加载前，将本 Mod 的 `lang/zh.ini` 自动复制到原 Nitoryu Workshop 目录：

```
<Steam Workshop>\\content\\233860\\3812165089\\lang\\zh.ini
```

这等价于手动把 `zh.ini` 放入原 Nitoryu 的 `lang` 文件夹，同时不修改 Nitoryu 的 `.mod` 数据文件。

## 安装

本 Mod 作为独立 Kenshi Mod 安装，并加载在原版 Nitoryu 之后。

依赖：
- Nitoryu
- RE_Kenshi（用于加载汉化桥接 DLL）

目录结构：

```
Nitoryu CN/
├── Nitoryu CN.mod
├── RE_Kenshi.json
├── NitoryuCNBridge.dll
└── lang/
    └── zh.ini
```

不要手动把 `zh.ini` 放入原 Nitoryu Workshop 文件夹；启动游戏时桥接 DLL 会自动处理。

## 翻译说明

- 所有 54 个文本 key 均已翻译。
- 保留原有 key。
- 保留 `{dp}`、`{amb}`、`{who}`、`{rank}`、`{next}`、`{x}` 等占位符。
- 使用 UTF-8 编码。
- 已使用作者提供的 `lang_check.py` 检查，结果为 **54/54（100%）**。

## 文件

- `Nitoryu CN.mod`：附属 Mod 定义，依赖 `Nitoryu.mod`。
- `RE_Kenshi.json`：在 Nitoryu 加载前加载桥接 DLL。
- `NitoryuCNBridge.dll`：把中文语言文件复制到原 Nitoryu 的 `lang` 目录。
- `lang/zh.ini`：中文语言文件。
