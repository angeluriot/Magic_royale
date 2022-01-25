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
| <img src="https://i.imgur.com/aCytEtE.png" height="100"><br/>**Royal Recruits** | Human | 4 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 5 / 4 | `Multi Hit` | |
| <img src="https://i.imgur.com/IRyHPmn.png" height="100"><br/>**Ice Golem** | Golem | 1 ![Green](https://i.imgur.com/wAQXqTG.png) | 1 / 3 | `Unblockable`, `Freeze` | Applies the effects of the Freeze capacity to all opponent creatures on death. |
| <img src="https://i.imgur.com/zCwYjyZ.png" height="100"><br/>**Elixir Golem** | Golem | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | 1 / 4 | `Unblockable` | Spawns 1 Elixir Golemites on death. Elixir Golemites spawns 1 Sentient Blobs on death. Sentient Blobs gives 2 Forest cards to the opponent on death. |
| <img src="https://i.imgur.com/VcjPaX9.png" height="100"><br/>**Dart Goblin** | Goblin | 2 ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 2 | `Reach` | |
| <img src="https://i.imgur.com/N54TT37.png" height="100"><br/>**Mega Minion** | Minion | 2 ![Blue](https://i.imgur.com/mIKhvAF.png) | 2 / 3 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/MTG0aib.png" height="100"><br/>**Battle Healer** | Angel | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 1 / 3 | `Flying`, `Reach` | Adds 1 toughness to all ally creatures while alive. |
| <img src="https://i.imgur.com/4O5vBzt.png" height="100"><br/>**Flying Machine** | Machine | 3 ![White](https://i.imgur.com/23AueSy.png) | 2 / 4 | `Flying`, `Reach` | |
| <img src="https://i.imgur.com/LTHr2Vs.png" height="100"><br/>**Zappies** | Machine | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 3 | `Reach`, `Freeze` | |
| <img src="https://i.imgur.com/0ArQF4i.png" height="100"><br/>**Battle Ram** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) | 3 / 1 | `Haste`, `Unblockable`, `Kamikaze` | Spawns 1 Barbarian on death. |
| <img src="https://i.imgur.com/TO2JDw0.png" height="100"><br/>**Hog Rider** | Boar | 3 ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 3 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/kFXRIRI.png" height="100"><br/>**Mini Pekka** | Demon | 2 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 2 | | |
| <img src="https://i.imgur.com/GQ3PU4b.png" height="100"><br/>**Musketeer** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 3 | `Reach` | |
| <img src="https://i.imgur.com/h0j3dXs.png" height="100"><br/>**Valkyrie** | Human | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 2 / 4 | `Zone Damage` | |
| <img src="https://i.imgur.com/8Gbkc15.png" height="100"><br/>**Wizard** | Wizard | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 4 / 3 | `Reach`, `Zone Damage` | |
| <img src="https://i.imgur.com/0C28J9h.png" height="100"><br/>**Royal Hogs** | Boar | 3 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 4 / 3 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/hwMIuWs.png" height="100"><br/>**Giant** | Giant | 3 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 2 / 5 | `Unblockable` | |
| <img src="https://i.imgur.com/fMBmVT3.png" height="100"><br/>**Three Musketeers** | Human | 6 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 6 / 5 | `Reach` | |
| <img src="https://i.imgur.com/VUq9QII.png" height="100"><br/>**Wall Breakers** | Skeleton | 1 ![Black](https://i.imgur.com/FOgaANE.png) | 5 / 2 | `Unblockable`, `Kamikaze` | |
| <img src="https://i.imgur.com/0Hvr81k.png" height="100"><br/>**Barbarian Barrel** | Human | 1 ![White](https://i.imgur.com/23AueSy.png) | 2 / 2 | `Haste` | Inflicts 1 damage to all enemy creatures on spawn. |
| <img src="https://i.imgur.com/qdJcuep.png" height="100"><br/>**Guards** | Skeleton | 2 ![Black](https://i.imgur.com/FOgaANE.png) | 2 / 3 | `Shield` | |
| <img src="https://i.imgur.com/EphIYxU.png" height="100"><br/>**Skeleton Army** | Skeleton | 2 ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 1 | `Multi Hit` | |
| <img src="https://i.imgur.com/9P3uC44.png" height="100"><br/>**Goblin Barrel** | Goblin | 2 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 2 | `Haste`, `Unblockable` | |
| <img src="https://i.imgur.com/bfFlRGY.png" height="100"><br/>**Hunter** | Humain | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 3 | `Reach`, `Multi Hit`, `Zone Damage` | |
| <img src="https://i.imgur.com/8WD6DLs.png" height="100"><br/>**Dark Prince** | Knight | 2 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 2 / 4 | `Haste`, `Zone Damage`, `Shield` | |
| <img src="https://i.imgur.com/zX1y63x.png" height="100"><br/>**Baby Dragon** | Dragon | 3 ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 3 | `Flying`, `Reach`, `Zone Damage` | |
| <img src="https://i.imgur.com/56G9WCU.png" height="100"><br/>**Electro Dragon** | Dragon | 3 ![Blue](https://i.imgur.com/mIKhvAF.png) ![Blue](https://i.imgur.com/mIKhvAF.png) | 4 / 3 | `Flying`, `Reach`, `Freeze` | |
| <img src="https://i.imgur.com/rxwhdoY.png" height="100"><br/>**Cannon Cart** | Machine | 4 ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | | Spawns 1 Cannon on death. |
| <img src="https://i.imgur.com/Bf0MVSe.png" height="100"><br/>**Executioner** | Human | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 3 / 4 | `Multi Hit`, `Reach` | |
| <img src="https://i.imgur.com/ZnynJFK.png" height="100"><br/>**Bowler** | Goblin | 3 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 4 | `Zone Damage`, `Multi Hit` | |
| <img src="https://i.imgur.com/mE27QBU.png" height="100"><br/>**Prince** | Knight | 3 ![White](https://i.imgur.com/23AueSy.png) ![White](https://i.imgur.com/23AueSy.png) | 4 / 3 | `First Strike`, `Haste` | |
| <img src="https://i.imgur.com/JYyqA2C.png" height="100"><br/>**Witch** | Wizard | 4 ![Blue](https://i.imgur.com/mIKhvAF.png) | 3 / 4 | `Reach`, `Zone Damage` | Spawns 1 Skeleton every turn. |
| <img src="https://i.imgur.com/AiuozVy.png" height="100"><br/>**Balloon** | Skeleton | 3 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 5 / 2 | `Flying`, `Unblockable`, `Zone Damage` | Inflicts 1 damage to all enemy creatures on death. |
| <img src="https://i.imgur.com/NTWy762.png" height="100"><br/>**Goblin Giant** | Goblin | 4 ![Red](https://i.imgur.com/KUtPu2A.png) ![Red](https://i.imgur.com/KUtPu2A.png) | 3 / 5 | `Reach`, `Unblockable` | Spawns 1 Spear Goblins on death |
| <img src="https://i.imgur.com/d3axxNd.png" height="100"><br/>**Giant Skeleton** | Skeleton | 4 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 2 / 6 | Capacity | Inflicts 3 damage to all enemy creatures on death. |
| <img src="https://i.imgur.com/39mEPiV.png" height="100"><br/>**Pekka** | Demon | 5 ![Black](https://i.imgur.com/FOgaANE.png) ![Black](https://i.imgur.com/FOgaANE.png) | 4 / 5 | | |
| <img src="https://i.imgur.com/p2uIjqR.png" height="100"><br/>**Electro Giant** | Giant | 5 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 3 / 7 | `Reach`, `Unblockable`, `Freeze` | |
| <img src="https://i.imgur.com/GiMOBzC.png" height="100"><br/>**Golem** | Golem | 6 ![Green](https://i.imgur.com/wAQXqTG.png) ![Green](https://i.imgur.com/wAQXqTG.png) | 2 / 8 | `Unblockable` | Inflicts 1 damage to all enemy creatures and spawns 1 Golemites on death. Golemites also inflicts 1 damage to all enemy creatures on death. |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
| <img src="" height="100"><br/>**Name** | Type | Price | Power / Toughness | Capacity | Unique ability |
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
