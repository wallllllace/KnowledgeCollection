import { makeAutoObservable } from "mobx";

class User {
    name = "";
    todos = [];
    constructor(name) {
        makeAutoObservable(this);
        this.name = name;
        // this.todos = ["吃早饭", "跑步", "洗衣服", "打扫卫生", "看书"];
        this.todos = [new Todo("吃早饭"), 
                        new Todo("跑步"), 
                        new Todo("洗衣服"),
                        new Todo("打扫卫生"),
                        new Todo("看书")];
    }

    get unfinishedCount() {
        return this.todos.filter(todo => !todo.finished).length;
    }

    changeName(newName) {
        this.name = newName;
    }

    addTask(task) {
        const newTask = new Todo(task);
        this.todos.push(newTask);
    }

}

export class Todo {
    title = "";
    finished = false;

    constructor(title) {
        makeAutoObservable(this);
        this.title = title;
    }

    done() {
        this.finished = true;
    }
}

export default new User("Wallace");