import React, { createContext } from 'react'
import Timer from './Timer';
import TimerView from './TimerView';
import TodoListView from './TodoListView';


export const TimerContext = createContext();

class App extends React.Component {

    render() {

        const mytimer =  new Timer();
        setInterval(() => {mytimer.increase()}, 1000);

        return (
            <div>
                <h1>hello world</h1>
                <p>这就是内容</p>
                <TimerContext.Provider value={mytimer}>
                    <TimerView />
                </TimerContext.Provider>
                <TodoListView />
                {/* <button onClick={() => this.reset()}>已过秒数：{this.state.secondsPassed}</button> */}
            </div>
        );
    }
}

export default App;

