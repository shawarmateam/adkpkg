# adkPKG

This is the package manager for **Linux** by adk. *(adisteyf)*.
You can add custom packages or download existing.

## How to install adkPKG

To install **adkPKG** follow these steps:

1. **Create the folders in your `$HOME` directory:**

```
cd;mkdir -p apps/c/adkpkg
```

2. **Clone repo into the *adkPKG* folder.**

```
git clone https://github.com/shawarmateam/adkpkg.git apps/c/adkpkg
```

3. **Create the `/adkbin` directory:**

```
sudo mkdir /adkbin
```

4. **Build *adkpkg*:**

```
cd apps/c/adkpkg;sudo make clean install
```

5. **Add** `/adkbin` to **`$PATH`** in your shell configuration:

- fish:

```
echo "" >> ~/.config/fish/config.fish;echo "set PATH /adkbin $PATH" >> ~/.config/fish/config.fish
```

- bash:

```
echo "" >> ~/.bashrc;echo 'export PATH="$PATH:/adkbin"' >> ~/.bashrc;source ~/.bashrc
```

- zsh:

```
echo "" >> ~/.zshrc;echo 'export PATH="$PATH:/adkbin"' >> ~/.zshrc;source ~/.zshrc
```

### Verification

To verify that **adkPKG** is working properly, run the following command:

```shell
adkpkg -p adkpkg
```

If the command returns the path of **adkPKG**, then the installation was successful!

### Additional Information

- **Dependencies**: Ensure you have the necessary build tools installed (e.g., `make`, `gcc`, etc.) before proceeding with the installation.
- **Usage**: For more information on how to use **adkPKG**, refer to the documentation or run `adkpkg --help` after installation.
- **Contributing**: If you would like to contribute to the development of **adkPKG**, please fork the repository and submit a pull request.

### License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/shawarmateam/adkpkg/blob/main/LICENSE) file for details.

---

Feel free to modify any sections further based on your specific requirements or additional features of **adkPKG**!
