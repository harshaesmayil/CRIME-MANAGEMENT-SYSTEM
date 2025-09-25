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

##📸 Demo Output

- Menu interface and Adding Report

 CRIME REPORTING AND RESPONSE SYSTEM 
 1. Add Report
 2. Delete Report
 3. View Pending
 4. Dispatch
 5. Mark Resolved
 6. Show Units
 7. Show Log
 8. Show Stats
 9. Exit
 Choice: 1
 Enter description: Theft
 Enter severity ( 1 - 5 ( 5 being the greatest priority ) ): 1
 Report 1 added.

- Unit status dashboard

--- Units ---
Unit 1: Busy (Report Assigned)
Unit 2: Free (Report None)
Unit 3: Free (Report None)

- Dispatch log view

--- Dispatch Log ---
Report 2 | Sev:5 | murder panampilly | Status: Resolved
Report 1 | Sev:1 | Theft | Status: Resolved

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
