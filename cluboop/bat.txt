@echo off
chcp 65001 > nul
echo 🔁 Конвертація .cpp та .h у UTF-8 ...

for /R %%f in (*.cpp *.h) do (
    powershell -Command ^
    "$content = Get-Content -LiteralPath '%%f' -Raw; ^
     [System.IO.File]::WriteAllText('%%f', $content, [System.Text.Encoding]::UTF8); ^
     Write-Host '✔ Converted: %%f'"
)

echo.
echo  Готово!
pause
