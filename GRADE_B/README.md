# Project Name

Work developed for the discipline **Algorithms and Programming: Fundamentals**.

## 👥 Group Members

- Pedro Henrique Fermino Klein
- Nicoly de Ávila Barros
- Gustavo Lima

## 🚀 How to Run

This program is written in **C** and can run using [OnlineGDB](https://www.onlinegdb.com/) or your favorite editor (e.g., VS Code).

### On OnlineGDB:
1. Copy and paste the code on the site.
2. Click "Run".

### On Your Computer:
1. Download or clone the repository.
2. Compile with: `gcc main.c -o program`
3. Run with: `./program`

## 💡 About the Program

The program simulates a turn-based combat battle between two parties. Each party consists of characters that belong to one of the following classes, each with unique special abilities:

- **Warrior:** Has a chance to deliver a critical hit that deals double damage.
- **Mage:** May cast a powerful fireball that bypasses the enemy's defense.
- **Ranger:** Can perform a double strike, effectively getting an extra attack in one turn.
- **Paladin:** Possesses a healing ability that sometimes restores a portion of health when attacked.
- **Barbarian:** Never misses an attack, making their blows consistently reliable.

Before combat starts, one party is drawn at random to attack first. The battle then proceeds round by round until every member of one party is defeated (i.e., their HP drops to 0).

## 📌 Comments

- The code is in the file `main.c`.
- No extra libraries are needed.
