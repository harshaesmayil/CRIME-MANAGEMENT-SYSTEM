# Contributing Guidelines

👋 Welcome! Thanks for helping build the Crime Reporting & Response System.

## Branching
- Each teammate works on **their own feature branch**.  
- **Never commit directly to main or dev** during development.
- Branch naming:
  - Gayathry → `feature/gayathry-dll-core`
  - Gouri → `feature/gouri-dispatch-priority`
  - Hathim → `feature/hathim-units-stats`
  - Irene → `feature/irene-log-stack`
  - Harsha → `feature/harsha-menu-ui`

## Commits
- Use clear messages:  
  - `feat: ...`, `fix: ...`, `refactor: ...`, `docs: ...`, `chore: ...`  
- Link an issue if possible: `(#3)`.  
- Commit **only your assigned files**.

## Workflow
1. Clone the repository.
2. Switch to your assigned branch.
3. Code in VS Code, edit only your assigned files.
4. Commit changes → Push to GitHub.
5. **Do not touch anyone else’s branch**.
6. At the end, Harsha merges everyone’s branch into `dev` for integration.

## Code Style
- Build locally with `gcc -std=c11 -Wall -Wextra`.
- Keep functions small; comment tricky parts.

## Testing
- Run your code and test menu options before pushing.
- CI will only check compilation; no automatic PR review is used.

## Communication
- Use **Issues** for bugs or tasks.
- Use **Project board** to track overall progress.
