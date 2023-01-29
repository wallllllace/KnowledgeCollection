import { makeAutoObservable } from "mobx"
import React, { useContext } from "react";
import { observer } from "mobx-react"
import { TimerContext } from "./App";

export class Timer {
    secondsPassed = 0;

    constructor() {
        makeAutoObservable(this);
    }

    increase() {
        this.secondsPassed += 1;
    }

    reset() {
        this.secondsPassed = 0;
    }
}

class TimerView extends React.Component {

    render(){
        const TimerBtn = observer(() => {
            const timer = useContext(TimerContext);
            return (
                <button onClick={() => timer.reset()}>已过秒数：{timer.secondsPassed}</button>
            );
        });
        return (
            <>
            <TimerBtn />
            </> 
        );

    }
}

export default TimerView;


