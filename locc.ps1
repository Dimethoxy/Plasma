# Specify the directory path
$directoryPath = "./Source"  # Replace with your directory path

# Initialize a variable to store the total LOC
$totalLoc = 0

# Use Get-ChildItem to locate code files recursively and iterate over them
$files = Get-ChildItem -Path $directoryPath -File -Include *.h,*.cpp -Recurse

foreach ($file in $files) {
    $loc = (Get-Content $file.FullName | Measure-Object -Line).Lines
    Write-Host "File: $($file.FullName), LOC: $loc"
    $totalLoc += $loc
}

Write-Host "Total LOC in folder: $totalLoc"