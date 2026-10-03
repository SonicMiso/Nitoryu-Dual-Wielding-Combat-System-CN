# Nitoryu CN

这是 [Nitoryu: Dual Wielding Combat System](https://steamcommunity.com/sharedfiles/filedetails/?id=3812165089) 的中文翻译 Mod，Mod 名称为 `Nitoryu CN`。

## 安装

安装后目录结构为：

```text
Nitoryu CN/
├── Nitoryu CN.mod
└── Nitoryu/
    └── lang/
        └── zh.ini
```

将整个 `Nitoryu CN` 文件夹放入 Kenshi 的 `mods` 目录，然后在 Mod Manager 中启用 `Nitoryu CN`，并将它放在原版 `Nitoryu` 后面。

Nitoryu 会根据 Kenshi 的语言自动选择 `zh`；也可以在 `Nitoryu.ini` 的 `[General]` 中设置：

```ini
language=zh
```

如果同时存在多个 Nitoryu 副本，请确保只加载一个本体，避免插件检测到重复实例。

## 翻译说明

翻译严格按照原 Mod 的 `lang/TRANSLATING.md` 制作：

- 所有 54 个文本 key 均已翻译。
- 保留原有 key。
- 保留 `{dp}`、`{amb}`、`{who}`、`{rank}`、`{next}`、`{x}` 等占位符。
- 使用 UTF-8 编码。
- 已使用作者提供的 `lang_check.py` 检查，结果为 **54/54（100%）**。

Kenshi 原版常用术语参考现有中文数据，例如「灵巧性」「近战攻击」「近战防御」「武士刀」「军刀」等。

## 目录

- `Nitoryu CN/Nitoryu CN.mod`：用于 Kenshi Mod Manager 识别的独立 Mod 文件
- `Nitoryu CN/Nitoryu/lang/zh.ini`：中文语言文件
