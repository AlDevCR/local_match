#!/bin/bash
cp git-pre-commit-format .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
echo "pre-commit format was installed."
