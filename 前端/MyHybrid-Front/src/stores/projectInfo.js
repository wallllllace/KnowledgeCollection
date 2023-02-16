import { makeAutoObservable } from "mobx";

export class ProjectRow {
    projectName = 'aaa';
    projectId = '23444';
    offRes = new Gray();
    preloadData = new Gray();
    creater = '';
    status = '';
    operate = [];

    constructor(projectName, projectId, offRes, preloadData, creater, status, operate) {
        makeAutoObservable(this);
        this.projectName = projectName;
        this.projectId = projectId;
        this.offRes = new Gray(offRes.apple, offRes.android);
        this.preloadData = new Gray(preloadData.apple, preloadData.android);
        this.creater = creater;
        this.status = status;
        this.operate = operate;
    }
}

export class Gray {
    apple = '';
    android = '';

    constructor(apple, android) {
        makeAutoObservable(this);
        this.apple = apple;
        this.android = android;
    } 
}

class Projects {
    list=[];

    constructor() {
        makeAutoObservable(this);
    }

    setList(list) {
        this.list = list;
    }

    addProject(project) {
        this.list.push(project);
    }
}

export default new Projects();


