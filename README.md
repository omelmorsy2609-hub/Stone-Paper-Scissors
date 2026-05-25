# Stone, Paper, Scissors (C++)

An interactive, multi-round Command-Line Interface (CLI) implementation of the classic **Stone, Paper, Scissors** game built in C++. 

This project goes beyond basic conditions to showcase structured programming using standard formatting, pseudo-random computing, console visual manipulation, and data encapsulation via structs and enums.

---

## 🎮 Features & Highlights

* **Custom Round Configuration:** Allows players to specify a match duration ranging from 1 to 10 rounds with built-in input validation.
* **Dynamic Visual Feedback:** Modifies the system console background/text color dynamically depending on outcomes:
    *  **Green** background on Player victory.
    *  **Red** background (accompanied by a system audio alert beep) when the Computer takes a win.
    *  **Yellow** background for a tied match.
* **Comprehensive Session Tracking:** Aggregates individual data structures per round to present an organized scoreboard at the end of the entire match.
* **Replay System:** Offers an intuitive restart loop (`y/n`) prompting players for subsequent matches while resetting tracking components smoothly.

---

## Code Architecture

The application is written cleanly using native structural definitions to decouple game metrics from logic tracking:

### Strongly-Typed Data Mapping (`enum`)
* `enGameChoice`: Defines the valid elements: `stone (1)`, `paper (2)`, or `scissors (3)`.
* `enWinner`: Maps possible outcomes uniformly: `Player1 (1)`, `Computer (2)`, or `Draw (3)`.

### Encapsulated State Management (`struct`)
* `stRoundInfo`: Retains live localized factors of an individual round (round index, choices made, result status, and winner string).
* `stGameResults`: Collects final cumulative statistics (total rounds, win metrics per entity, total ties, and the verified absolute winner).

---

## How to Compile and Run

To run this application locally, you will need a standard C++ compiler (such as `GCC / G++`).
