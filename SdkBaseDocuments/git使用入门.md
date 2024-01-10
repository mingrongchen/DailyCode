# Git使用入门


Git是一个分布式版本控制系统，用于跟踪文件的变化并协作开发。以下是Git的一些基本概念和常用命令的详解：

### Git基本概念：

1. **仓库（Repository）**：包含项目所有文件和历史记录的地方。
2. **工作区（Working Directory）**：包含实际项目文件的目录，可见和修改的文件都在这里。
3. **暂存区（Staging Area）**：一个中间区域，用于暂时存放修改，将其添加到暂存区后可以一次性提交到版本历史。
4. **提交（Commit）**：将暂存区的修改保存到版本历史中，形成一个新的提交。
5. **分支（Branch）**：一个独立的线索，代表项目的一个不同状态，可以用于并行开发和实验。
6. **合并（Merge）**：将两个分支的修改合并到一个新的提交中。

### 常用Git命令：

1. **git init**: 初始化一个新的仓库。

   ```
   bashCopy code
   git init
   ```

2. **git clone**: 从远程仓库克隆一个本地副本。

   ```
   bashCopy code
   git clone <repository_url>
   ```

3. **git add**: 将工作区的修改添加到暂存区。

   ```
   bashCopy code
   git add <file>
   ```

4. **git commit**: 将暂存区的修改提交到版本历史。

   ```
   bashCopy code
   git commit -m "Commit message"
   ```

5. **git status**: 查看工作区和暂存区的状态。

   ```
   bashCopy code
   git status
   ```

6. **git log**: 查看提交历史。

   ```
   bashCopy code
   git log
   ```

7. **git branch**: 列出所有分支，创建新分支，或切换到指定分支。

   ```
   bashCopy codegit branch
   git branch <branch_name>
   git checkout <branch_name>
   ```

8. **git merge**: 合并指定分支到当前分支。

   ```
   bashCopy code
   git merge <branch_name>
   ```

9. **git pull**: 从远程仓库拉取最新修改。

   ```
   bashCopy code
   git pull origin <branch_name>
   ```

10. **git push**: 推送本地修改到远程仓库。

    ```
    bashCopy code
    git push origin <branch_name>
    ```

11. **git remote**: 管理远程仓库。

    ```
    bashCopy code
    git remote -v
    ```

12. **git diff**: 查看工作区和版本历史之间的差异。

    ```
    bashCopy code
    git diff
    ```

13. **git rm**: 从工作区和版本历史中删除文件。

    ```
    bashCopy code
    git rm <file>
    ```

14. **git tag**: 标记一个特定的提交。

    ```
    bashCopy code
    git tag <tag_name>
    ```

这只是Git的一小部分命令，Git有很多功能和选项，可以根据实际需求进行深入学习。为了更详细的理解和学习，你可以查阅Pro Git这本开源的Git书籍。