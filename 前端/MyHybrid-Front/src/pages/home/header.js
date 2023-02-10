import React from "react";
import { observer } from "mobx-react";
import { Button } from "antd";
import "./header.scss";

const Header = () => {

    const Content = () => {
        return (
            <div className="header-content-container">
                <div className="header-content-bgimg"></div>
                <div className="header-content-title-container">
                    <span className="header-content-title-big-container">JDHybrid</span>
                    平台介绍
                </div>
                <div className="header-content-body-container">
                JDHybrid是一个移动端高性能Hybrid容器框架，致力于提升h5在京东App内的加载与渲染性能，目前已经过了40+业务的验证，包括春晚、双十一等大流量场景，收益明显，稳定性佳；接入业务性能提升平均30%+，tp50～tp95多个维度的提升均很明显；接入业务加载错误率也大幅降低，可有效降低业务白屏等不良体验；后续JDHybrid还将在h5秒开、页面组件渲染、web组件标准化（如jsbridge标准组件）等多个维度进一步探索h5的性能提升与开发提效的措施，真诚欢迎各h5业务、各app了解、试用、使用并提出宝贵建议。
                </div>
                <div className="header-content-create-container">
                    <Button className="header-content-create-button" type="text" onClick={(e) => {
                        console.log('创建项目');
                    }}>立即创建</Button>
                </div>
                <div className="header-content-link-container">
                    <span>友情链接：</span>
                    <span>pubfree</span>
                    <span>ipaas</span>
                    <span>xview2</span>
                    <span>switchquery</span>
                </div>
            </div>
        );
    };

    return (
        <div>
            <Content/>
        </div>
    );
};

export default observer(Header);