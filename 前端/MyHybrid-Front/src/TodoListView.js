import { makeObservable, observable, action, computed, autorun } from "mobx";
import { observer } from "mobx-react-lite";
import React from "react";

class Todo {
    id = Math.random();
    title = "";
    finished = false;

    constructor(title) {
        makeObservable(this, {
            title: observable,
            finished: observable,
            toggle: action
        });
        this.title = title;
    }

    toggle() {
        this.finished = !this.finished;
    }
}

class TodoList {
    todos = [];
    constructor(todos) {
        makeObservable(this, {
            todos: observable,
            unfinishedTodoCount: computed
        });
        this.todos = todos;
    }

    get unfinishedTodoCount() {
        return this.todos.filter(todo => !todo.finished).length;
    }
}


class TodoListView extends React.Component {
    render() {
        const TodoView = observer(({ todo }) => (
            <li>
                <input type="checkbox" checked={todo.finished} onClick={() => todo.toggle()} />
                {todo.title}
            </li>
        ));
        const TodoListView = observer(({todoList}) => (
            <div>
                <ul>
                    {todoList.todos.map(todo => (
                        <TodoView todo={todo} key={todo.id} />
                    ))}
                </ul>
                Task left: {todoList.unfinishedTodoCount}
            </div>
        ));

        const store = new TodoList([new Todo("Get Coffee"), new Todo("running"), new Todo("eat breakfirst")]);
        return (
            <>
            <TodoListView todoList={store}/>
            </>
        );
    }
}

export default TodoListView;