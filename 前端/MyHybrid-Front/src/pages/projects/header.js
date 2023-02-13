import React from "react";
import { observer, Observer } from "mobx-react";
import { Input, Button } from "antd";
import "./header.scss";


const Header = () => {

    const Title = () => (
        <div className="project-header-title-container">项目管理</div>
    );

    const Search = () => (
        <div className="project-header-search-container">
            <Input placeholder="请输入 项目名称/创建人erp/hybridid/页面URL 搜索" 
            onChange={(e) => {
                console.log(e.target.value);
            }}
            onPressEnter={(e) => {
                console.log(e.target.value);
            }}
            />
        </div>
    );

    const CreateBtn = () => (
        <div className="project-header-createBtn-container">
            <Button type="text" onClick={(e) => {
                console.log(e);
            }} >新建项目</Button>
        </div>
    );


    return (
        <div className="project-header-container">
            <Title />
            <Search />
            <CreateBtn />
        </div>
    );
};

export default observer(Header);