# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]
### Changed

- Tweaked overworld sprites and backsprites for Gold and Kris (with help from [@ShinyDragonHunter](https://github.com/ShinyDragonHunter)).

### Added

- Miscellanous files (map screenshots, concept art for new title screen, etc) in other/.
- New Kris, Firebreather, Rival, and female Rocket Grunt trainer sprites (credit to Momento Rori/RoryAllegory)
- Morning and night battle terrain variants for all outdoor terrain types.
- Surfing animation from FireRed (credit to [@ShinyDragonHunter](https://github.com/ShinyDragonHunter)).
- Flying animation from FireRed (credit to [@ShinyDragonHunter](https://github.com/ShinyDragonHunter)).
- Game Boy Player/Sounds music engine, a port of Crystal's sound engine to GBA ([@Jambo51](https://github.com/Jambo51), [@ShantyTown](https://github.com/huderlem), and myself).

### Fixed

- Fixed Ruins of Alph rear room pedestal collisions and other minor map issues.
- Legacy builds (i.e. using agbcc and not the modern compiler) work now.
- Fixed a possible crash when both enemy and player Pokémon faint at the same time on certain emulators.
- Fixed the Machop "MUSCLE" in-game trade having the wrong gender (should be female).
- Fixed the Onix "ROCKY" in-game trade having the wrong OT (should be "KYLE").
- Fixed the lowest trigger for the Dude catching tutorial walking the player on top of the Dude.
- Fixed the Youngster overworld having one frame too low.
- Fixed a typo with Youngster Samuel's defeat text ("Beaten by a pass**s**ing stranger!").
- Fixed a bug with certain Pokémon floating after hatching.
- Fixed phone service being available in certain areas where it shouldn't have been.
- Fixed memory leak in Oak speech when entering/exiting naming screen.

## [v3.0.0-alpha.0.5] - 2021-01-04
### Changed

- Made Game Corner TMs not be duplicates of Goldenrod Dept. Store TMs.

### Fixed

- Fixed moving items around in the item PC.
- Fixed chair in front of the Day-Care Lady's desk.
- Fixed metatile in Goldenrod Dept. Store 1F not being accessible from the right.
- Fixed top Card Flip machine in Game Corner not being usable.
- Picnicker Erin on Route 46 now uses the right overworld sprite.
- Violet City trader no longer moves after trade completes.
- Sanitized department store tileset for incorrect metatile behaviors.
- Mom no longer calls every time you talk to the Day-Care Man outdoors.
- Fixed a crash when Mimic is used.
- Fixed collisions with trees on 3F and 4F of Goldenrod Dept. Store.

## [v3.0.0-alpha.0.4] - 2020-12-30
### Fixed

- Fixed all metatiles being the Town Map when not facing north.

## [v3.0.0-alpha.0.3] - 2020-12-30
### Fixed

- Various link and Union Room bugs were fixed, including one where the official games would not want to trade certain Pokémon to us because they didn't like that we weren't the Champion yet.
- Have the money the player loses upon whiteout be subtracted from the current count instead of _becoming_ the current count.
- Sprites no longer appear on top of Mr. Pokémon's computer.
- Ilex Forest nighttime encounters are correct and no longer just a copy of the daytime encounters.
- Fixed Decamark (??????????) Pokémon appearing when using Rock Smash in Dark Cave when it's not morning.
- Fixed Violet City cut tree not appearing when warping in from east.
- Fixed unevolved Pokémon sprite not growing & shrinking during evolution animation.

## [v3.0.0-alpha.0.2] - 2020-12-27
### Added

- Ball particles for some of the Apricorn Balls by [@huderlem](https://github.com/huderlem).
- Flower animations for flowers in Goldenrod City gym and Pretty Petal Flower Shop.

### Changed

- Headbutt tree tile, so it doesn't look weird when layered over a wooden fence.

### Fixed

- Dept. Store rooftop sale NPCs no longer appear when there isn't a sale (and right now, there is never a sale).
- Non-modern build no longer complains about unused song files.
- Fixed a bunch of undefined behaviors, which were causing crashes in emulators that don't know how to handle them. This fixes the game crash on staircases in My Boy!.
- Sanitized Radio Tower tileset for incorrect metatile behaviors. This stops the warp to a black map when interacting with machines and phones.
- Certain headbutt trees (specifically those under the tops of big trees) could not be headbutted; this has been fixed.
- Floria (the younger flower shop sister) no longer teleports around.
- Fixed minor text issues.

## [v3.0.0-alpha.0.1] - 2020-12-25
### Added

- Initial release, up through Sudowoodo event on Route 36

[unreleased]: https://github.com/Sierraffinity/CrystalDust/compare/v3.0.0-alpha.0.5...HEAD
[v3.0.0-alpha.0.5]: https://github.com/Sierraffinity/CrystalDust/releases/tag/v3.0.0-alpha.0.5
[v3.0.0-alpha.0.4]: https://github.com/Sierraffinity/CrystalDust/releases/tag/v3.0.0-alpha.0.4
[v3.0.0-alpha.0.3]: https://github.com/Sierraffinity/CrystalDust/releases/tag/v3.0.0-alpha.0.3
[v3.0.0-alpha.0.2]: https://github.com/Sierraffinity/CrystalDust/releases/tag/v3.0.0-alpha.0.2
[v3.0.0-alpha.0.1]: https://github.com/Sierraffinity/CrystalDust/releases/tag/v3.0.0-alpha.0.1
