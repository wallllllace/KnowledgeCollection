import React, { createContext } from 'react'
import timer from './Timer';
import TimerView from './TimerView';
import TodoListView from './TodoListView';
import { Provider } from 'mobx-react';
import  store  from './stores/index'
import UserView from './UserView';

export const TimerContext = createContext();


class App extends React.Component {

    render() {

        return (
            <div>
                <h1>hello world</h1>
                <p>这就是内容</p>
                <Provider timer={timer}>
                    <TimerView />
                </Provider>
                <Provider {...store}>
                    {/* <TodoListView /> */}
                    <UserView />
                </Provider>
                
                {/* <button onClick={() => this.reset()}>已过秒数：{this.state.secondsPassed}</button> */}
            </div>
        );
    }
}

export default App;

