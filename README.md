# 🚨 Crime Reporting & Response System

A modular C-based system designed to manage crime reports, dispatch police units, and maintain accountability logs. Built collaboratively by the DLL Team.

---

## 📁 Project Structure
src/
├── main.c # Menu and integration
├── reports.c/h # Crime report management (DLL)
├── dispatch.c/h # Police dispatch logic
├── units.c/h # Unit tracking and statistics
├── log.c/h # Dispatch log (stack)

---

## 🛠 Build Instructions

To compile and run the project locally:

```bash
gcc -std=c11 -Wall -Wextra src/*.c -o crime-system
./crime-system

---

## 👥 Team Roles

| Member     | Responsibility                        |
|------------|---------------------------------------|
| Harsha     | Main menu, integration, documentation |
| Gouri      | Dispatch logic, status updates        |
| Gayathry   | Report management (DLL)               |
| Hatim      | Unit tracking, statistics             |
| Irene      | Dispatch log (stack)                  |

---

🧪 Demo Scenario
A burglary is reported. Dispatcher assigns a unit. Status updates from Pending → In Progress → Resolved. Log entry created for accountability.


⚠️ Workflow Rules
Each teammate works only on their assigned branch.
Never commit directly to main.
Harsha will merge all feature branches into dev at the end of the project.
CI only ensures compilation; PR reviews are skipped.

---

##📸 Screenshots

Screenshots will be added to the screenshots/ folder once implementation begins:

- Menu interface

- Unit status dashboard
- Dispatch log view

---

📌 Contributing
We welcome contributions! Please read our CONTRIBUTING.md for guidelines on:
- Branch naming and commit messages
- Pull request process
- Code style and testing
- Review responsibilities


📄 License
This project is licensed under the MIT License.


📬 Contact
For questions, suggestions, or bug reports, open an Issue or reach out via GitHub.