# Datastructures Using C, 2nd edition, Reema Thareja

## References

### Useful Sites

- [Visualize algorithm](https://visualgo.net/en)
- [Regular expressions](https://regexr.com/)
- [cdecl: c expression decoder online](https://cdecl.org/)

### Free Lectures

### Vscode 

  ```
  "code-runner.executorMap": {
    // "c": "cd $dir && tcc -run $fileName",
    "c": "cd $dir && gcc -std=gnu11 $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt && rm *.exe",
    "cpp": "cd $dir && g++ -std=c++2a -fconcepts $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt && rm *.exe",
  }
  ```