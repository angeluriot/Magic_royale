# Magic Royale

![Release](https://img.shields.io/badge/Release-v1.0-blueviolet)
![Language](https://img.shields.io/badge/Language-C%2B%2B-0052cf)
![Size](https://img.shields.io/badge/Size-218Ko-f12222)
![Open Source](https://badges.frapsoft.com/os/v2/open-source.svg?v=103)

<br/>

This repository contains the source code of a simplified console clone of **[Magic the Gathering Arena](https://magic.wizards.com/en/mtgarena)** but using the cards of **[Clash Royale](https://clashroyale.com)**.

<br/>

<p align="center">
	<img src="https://i.imgur.com/J6jsG0h.png" width="700">
</p>

<br/>

# Summary

* **[Summary](#summary)**
* **[Features](#features)**
* **[Cards](#cards)**
	* [Lands](#lands)
	* [Creatures](#creatures)
	* [Spells](#spells)
* **[Install](#install)**
	* [Makefile](#makefile)
	* [CMake](#cmake)
* **[Releases](#releases)**
* **[Credits](#credits)**

<br/>

# Features

Text

<br/>

# Cards

Text

### Lands

Text

| Swamp | Island | Forest | Mountain | Plain |
| :-: | :-: | :-: | :-: | :-: |
| <img src="https://i.imgur.com/KphcUNf.png" height="180"> | <img src="https://i.imgur.com/YWiOqdI.png" height="180"> | <img src="https://i.imgur.com/U4tM6fS.png" height="180"> | <img src="https://i.imgur.com/7cehiJB.png" height="180"> | <img src="https://i.imgur.com/QaYI54P.png" height="180"> |
| ![Black](https://i.imgur.com/FOgaANE.png) Black | ![Blue](https://i.imgur.com/mIKhvAF.png) Blue | ![Green](https://i.imgur.com/wAQXqTG.png) Green | ![Red](https://i.imgur.com/KUtPu2A.png) Red | ![White](https://i.imgur.com/23AueSy.png) White |

### Creatures

Text

| Card | Type | Price | Power / Toughness | Capacities | Unique ability |
| :-: | :-: | :-: | :-: | :- | :- |
| <img src="https://i.imgur.com/ygCvjHx.png" height="100"><br/>**Electro Spirit** | Spirit | 1 | 2 / 1 | `Freeze`, `Kamikaze` | |
| <img src="https://i.imgur.com/GT0uFlD.png" height="100"><br/>**Fire Spirit** | Spirit | 1 | 2 / 1 | `Zone Damage`, `Kamikaze` | |
| <img src="https://i.imgur.com/Lt4i4aR.png" height="100"><br/>**Ice Spirit** | Spirit | 1 | 1 / 2 | `Freeze`, `Kamikaze` | |
| <img src="https://i.imgur.com/SvxOw6f.png" height="100"><br/>**Skeletons** | Skeleton | 1 | 2 / 1 | | |
| <img src="https://i.imgur.com/Iapwgco.png" height="100"><br/>**Bats** | Bat | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 1 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/fvjL2Xj.png" height="100"><br/>**Spear Goblins** | Goblin | 1 ![Red](https://i.imgur.com/KUtPu2A.png) | 2 / 2 | `Reach` | |
| <img src="https://i.imgur.com/lcXzhPC.png" height="100"><br/>**Bomber** | Skeleton | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 1 | `Zone Damage` | |
| <img src="https://i.imgur.com/ac1WLkK.png" height="100"><br/>**Goblins** | Goblin | 1 ![Red](https://i.imgur.com/KUtPu2A.png) | 2 / 2 | | |
| <img src="https://i.imgur.com/zlTZSbo.png" height="100"><br/>**Firecracker** | Human | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Reach`, `Multi Hit`, `Zone Damage` | |
| <img src="https://i.imgur.com/iiSBL4k.png" height="100"><br/>**Goblin Gang** | Goblin | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Reach` | Adds 1 power to all Goblin type allies while alive. |
| <img src="https://i.imgur.com/6xSK9Bh.png" height="100"><br/>**Minions** | Minion | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 2 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/HrjyHZH.png" height="100"><br/>**Archers** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) | 3 / 2 | `Reach` | |
| <img src="https://i.imgur.com/Le34AAm.png" height="100"><br/>**Knight** | Knight | 2 ![White](https://i.imgur.com/23AueSy.png) | 2 / 3 | | |
| <img src="https://i.imgur.com/6QbWZiD.png" height="100"><br/>**Skeleton Dragons** | Dragon | 2 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 3 / 3 | `Flying`, `Reach`, `Zone Damage` | |
| <img src="https://i.imgur.com/Kl0Om3v.png" height="100"><br/>**Rascals** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | `Reach` | |
| <img src="https://i.imgur.com/Beqplf6.png" height="100"><br/>**Minion Horde** | Minion | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 5 / 2 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/IjBmurT.png" height="100"><br/>**Barbarians** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 3 | | |
| <img src="https://i.imgur.com/lIHngL2.png" height="100"><br/>**Elite Barbarians** | Human | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 4 | | |
| <img src="https://i.imgur.com/Vu0jRDv.png" height="100"><br/>**Royal Giant** | Giant | 4 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 5 | `Reach`, `Unblockable` | |
| <img src="https://i.imgur.com/aCytEtE.png" height="100"><br/>**Royal Recruits** | Human | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 5 / 4 | `Multihit` | |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |

### Spells

Text

<br/>

# Install

Text

<br/>

# Releases

Text

<br/>

# Credits

* [**Angel Uriot**](https://github.com/angeluriot) : Co-creator of the project.
* [**Arthur Azambre**](https://github.com/arthurazambre) : Co-creator of the project.
