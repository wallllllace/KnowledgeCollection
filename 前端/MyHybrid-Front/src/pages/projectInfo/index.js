import React from "react";
import { observer } from "mobx-react";
import { Breadcrumb, Divider } from 'antd';
import { useHistory } from "react-router-dom";
import "./index.scss";
import qrcode from './qrcode.png';

const ProjectInfo = (project) => {
    // {title, projectId, type, spec, url}
    const projectInfo = {
        title: "白条频道页",
        projectId: "821807875423289344",
        type: 1,
        spec: "白条主流程：我京-白条，我钱-白条",
        url: "https://mcr.jd.com/credit_home/pages/index.html"
    };
    return (
        <div className="projectInfo-container">
            <div className="projectInfo-floatView-container"><FloatView /></div>
            <div className="projectInfo-breadcrumb-container">
                <BreadcrumbView title="aaa" />
            </div>
            <PrejectInfoTitleView {...projectInfo}></PrejectInfoTitleView>
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


const BreadcrumbView = ({title}) => {
    const history = useHistory();
    return (
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
};

const PrejectInfoTitleView = ({title, projectId, type, spec, url}) => {
    return (
        <>
        <div className="PrejectInfoTitleView-container-titleArea">
            <span className="PrejectInfoTitleView-container-titleArea-title">{title}</span>
            <span className="PrejectInfoTitleView-container-titleArea-projectId">{projectId}</span>
            <span className="PrejectInfoTitleView-container-titleArea-type">{type === 1 ? "单页面" : "多页面" }</span>
        </div>
        <div className="PrejectInfoTitleView-container-specArea">
            {spec}
        </div>
        <div className="PrejectInfoTitleView-container-urlArea">
            {url}
        </div>
        </>
    );
};

