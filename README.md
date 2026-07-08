# Ps5-Spotify-online-status-integration-workaround-test
The PS4 had a great built-in feature that seamlessly displayed the Spotify song you were listening to directly as your custom online status. Because companies like Sony tend to become soulless and money-driven with success, they routinely gut these beloved features to save on minor server space and cut corners (RIP PlayStation Communities as well 🙏).

This repository is an ongoing, highly experimental project utilizing a rooted/jailbroken PlayStation 5 to see if it's possible to reverse-engineer or spoof this feature back into existence, with the ultimate challenge of attempting to get online without immediately bricking the console or getting banned. So basically completely impossible, but so was flying, and that didn't stop the Wright brothers.

This repository is strictly a personal test environment and a proof-of-concept. The SOLE reason this isn't private, is because I have so many of those already and I figured someone might at least find my struggles entertaining.

Attempting to force custom status integration on a rooted PS5 while trying to interface with Sony's ecosystem introduces massive roadblocks. Any active development on this project has to clear the following hurdles:

  The PSN Connectivity Paradox: To display an online status, the console must talk to the PlayStation Network (PSN). However, a rooted PS5 requires blocking Sony's update and authentication servers to prevent an automatic firmware update or an immediate console ID (CID) ban.

  The "Brick" Risk: Messing with low-level system orchestration or trying to spoof firmware tokens to bypass Sony's network checks carries a high risk of permanently banning the console from network capabilities, or worse, causing a fatal system crash (bricking the hardware).

 API Sandboxing: Even if network spoofing is achieved, Sony's modern OS architecture partitions system apps differently than the PS4 did. Injecting a custom background daemon that pulls live data from the Spotify API and pipes it into the PSN status protocol is incredibly unstable.

do not try to compile or run anything found here, also this is NOT going to be made for view readability in mind.
