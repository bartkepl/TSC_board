# TSC (TimeStamp Counter)
TimeStamp Counter board, addon board to UCB_board 
![Time Stamp Counter board](media/TSC_board_angle.png)

| Top | Bottom |
|---|---|
| ![Top](media/TSC_board_front.png) | ![Bottom](media/TSC_board_back.png) |

---
## Status: ready for prototype order

- Schematic and PCB layout done (4-layer, 100 × 100 mm), production files generated.
- Design review completed; DRC/ERC clean (remaining items reviewed and excluded as by-design).
- Hand assembly (2 fiducials on F.Cu for stencil alignment); LM4040 references (U15/U32/U46/U60) are DNP in this revision.

Production outputs: [schematic PDF](prod/sch/TSC_board.pdf) · [PCB PDF](prod/pcb/TSC_board.pdf) · [interactive BOM](prod/ibom/TSC_board_ibom.html) · [gerbers](prod/TSC_board.zip)

---

## Features (with UCB_board):
- 2x4 timestamp ports with 0-25v input range and isolation
- 2x3 isolated counter ports 
- Digital threshold level control
- USB 2.0
- 10/100 Ethernet (based on WIZnet W5500)
- UART
- Half-duplex RS485 
- 3U eurocard IEEE 1101.1-1998 format (160x100 mm) — this 100 × 100 mm front module is combined with the UCB_board backend

## License and Contribution

[MIT License](/LICENSE)

Open to contributions in both software and hardware!