import { makeAutoObservable } from "mobx"

class Timer {
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

const timer = new Timer();
setInterval(() => {
    timer.increase();
}, 1000);

export default timer;