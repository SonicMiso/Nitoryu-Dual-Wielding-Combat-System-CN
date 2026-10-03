# Nitoryu CN

这是 [Nitoryu: Dual Wielding Combat System](https://steamcommunity.com/sharedfiles/filedetails/?id=3812165089) 的中文语言文件。

## 安装

按原作者 `TRANSLATING.md` 的设计，本项目不是重新打包或修改 Nitoryu 本体，而是只提供：

```
Nitoryu/
└── lang/
    └── zh.ini
```

将 `Nitoryu\lang\zh.ini` 放入 Nitoryu 所在的 Mod 文件夹中即可。

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

- `Nitoryu/lang/zh.ini`：中文语言文件
