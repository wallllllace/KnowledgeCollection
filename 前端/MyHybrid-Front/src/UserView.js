import React, {Button, useState} from "react";
import { useContext } from "react"
import { MobXProviderContext, observer } from "mobx-react"
import { observable } from "mobx";

const UserView = () => {
    const user = React.useContext(MobXProviderContext)["user"]
    return (
        <div>
            <h2>你好, {user.name}！</h2>
            <p>你有{user.unfinishedCount}件待处理：</p>
            <TodoList />
        </div>
    );
}

const TodoList = () => {
    const user = React.useContext(MobXProviderContext)["user"]
    const [task, setTask] = useState("");
    return (
        <div>
        <ul>
            {
                user.todos.filter(todo => !todo.finished).map(todo => {
                    return <TodoView  todo={todo}/>
                })
            }
        </ul>
        <input type="text" value={task} onChange={(event) => {
            setTask(event.target.value);
        }} /> 
        <button onClick={() => {
            user.addTask(task);
            setTask("");
        }}>添加</button>
        </div>  
    );
};

const TodoView = ({todo}) => {
    return (
        <li>
            <input type="checkbox" checked={todo.finished} onClick={() => todo.done()} />
            {todo.title}
        </li>
    );
};

export default observer(UserView);
