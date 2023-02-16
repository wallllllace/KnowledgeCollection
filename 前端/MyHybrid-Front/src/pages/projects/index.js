import React from "react";
import { Table, Button } from "antd";
import "./index.scss";
import Header from "./header";
import { CopyOutlined } from "@ant-design/icons";
import { Provider } from 'mobx-react';
import projects from "../../stores/projectInfo";
import { MobXProviderContext } from "mobx-react";
import ProjectTable from "./projectTable";
import { ProjectRow, Gray } from "../../stores/projectInfo";

export default () => {

    const row1 = new ProjectRow("2023-x-正式", 
                                "819549326722809856", 
                                {apple: "30%", android: "50%"}, 
                                {apple: "30%", android: "50%"},
                                "wangxiaorui19",
                                "进行中",
                                ["编辑","配置","查看","权限管理"]);
    const row2 = new ProjectRow("百亿补贴正式链接", 
                                "830863600109662208", 
                                {apple: "--", android: "50%"}, 
                                {apple: "30%", android: "--"},
                                "wangxiaorui19",
                                "进行中",
                                ["编辑","配置","查看","权限管理"]);
    const row3 = new ProjectRow("探馆定位UA", 
                                "809441262608756736", 
                                {apple: "30%", android: "50%"}, 
                                {apple: "--", android: "--"},
                                "wangxiaorui19",
                                "进行中",
                                ["编辑","配置","查看","权限管理"]);
    const row4 = new ProjectRow("首页调用-试用", 
                                "827140937247797248", 
                                {apple: "30%", android: "50%"}, 
                                {apple: "30%", android: "50%"},
                                "wangxiaorui19",
                                "进行中",
                                ["编辑","配置","查看","权限管理"]);
    projects.addProject(row1);
    projects.addProject(row2);
    projects.addProject(row3);
    projects.addProject(row4);

    
    return (
        <div className="project-container">
            <div>
                <Header />
            </div>
            <div>
            <Provider projects={projects}>
                <ProjectTable />
            </Provider>
            </div>
        </div>
    );
};