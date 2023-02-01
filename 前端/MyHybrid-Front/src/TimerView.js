import React, { useContext, useEffect } from "react";
import { observer } from "mobx-react"
import { TimerContext } from "./App";
import { MobXProviderContext } from "mobx-react";

// function TimerBtn(props) {
//     const TimerComponent = observer(props => {
//         const {timer} = React.useContext(MobXProviderContext);
//         useEffect(() => {
//             console.log(`时间改变了${timer.secondsPassed}`);
//         }, [timer.secondsPassed]);
//         return (
//             <button onClick={() => timer.reset()}>已过秒数：{timer.secondsPassed}</button>
//         );
//     });
//     return <TimerComponent />
// }

const TimerBtn = observer(props => {
    const {timer} = React.useContext(MobXProviderContext);
    useEffect(() => {
        console.log(`时间改变了${timer.secondsPassed}`);
    }, [timer.secondsPassed]);
    return (
        <button onClick={() => timer.reset()}>已过秒数：{timer.secondsPassed}</button>
    );
});

// export default function TimerView() {
// // const TimerBtn = timerBtn();
//            return  <TimerBtn />;
        
// }

 const TimerView = props => {
    return <TimerBtn />
 }

 export default TimerView;


