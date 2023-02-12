# Steganography project
Encrypt and decrypt messages in images.

# Usage
steganography.exe \[flags\] \[path_to_image\] \["message to encrypt"\]

## Available flags
- **-i** | **--info** _path_to_file_ => prints information about file specified in _path_to_file_
- **-e** | **--encrypt** _path_to_file_ _"message to encrypt"_ => checks if message can be encrypted in the image specified in _path_to_file_ and codes it inside
- **-d** | **--decrypt** _path_to_file_ => decrypts message encrypted in the file
- **-c** | **--check** _path_to_file_ _"message_to_encrypt"_ => checks if message can be encrypted in the image specified in _path_to_file_
- **-h** | **--help** => default flag. Shows usage and specs of the program

# Compilation
Used CMake bundled with CLion.