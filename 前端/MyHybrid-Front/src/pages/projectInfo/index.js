import React from "react";
import { observer } from "mobx-react";
import { Breadcrumb, Divider } from 'antd';
import { useHistory } from "react-router-dom";
import "./index.scss";
import qrcode from './qrcode.png';

const ProjectInfo = (project) => {
    const history = useHistory();

    const BreadcrumbView = ({title}) => (
        <>
        <Breadcrumb>
            <Breadcrumb.Item>
            <a onClick={(e) => {
                e.preventDefault();
                history.goBack();
            }}>项目管理</a>
            </Breadcrumb.Item>
            <Breadcrumb.Item>
            <span>{title}</span>
            </Breadcrumb.Item>
        </Breadcrumb>
        <Divider />
        </>
    );

    return (
        <div className="projectInfo-container">
            <div className="projectInfo-floatView-container"><FloatView /></div>
            <div className="projectInfo-breadcrumb-container">
                <BreadcrumbView title="aaa" />
            </div>
        </div>
    );
};

export default observer(ProjectInfo);

const FloatView = () => {
    return (
        <>
        <div className="projectInfo-floatView-operate-container">
            <div className="projectInfo-floatView-operate-container-btn" onClick={() => {
                console.log('点击了编辑');
             }}>编 辑</div>
            <div className="projectInfo-floatView-operate-container-btn" onClick={() => {
                console.log('点击了发布');
            }}>发 布</div>
        </div>
        <div className="projectInfo-floatView-qrcode-container">
            <div className="projectInfo-floatView-qrcode-container-title">离线包扫码测试</div>
            <div className="projectInfo-floatView-qrcode-container-img"><img src={qrcode}></img></div>
            <div className="projectInfo-floatView-qrcode-container-info">当前扫码可用离线包</div>
        </div>
        </>
    );
};

