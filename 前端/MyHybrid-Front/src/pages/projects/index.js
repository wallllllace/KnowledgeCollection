import React from "react";
import { Table } from "antd";
import "./index.scss";
import Header from "./header";

export default () => {

    const ProjectTitle = ({projectName, projectId}) => (
        <>
            <div>{projectName}</div>
            <div>{projectId}</div>
        </>
    );

    const Gray = ({apple, android}) => (
        <>
            <div>{apple}</div>
            <div>{android}</div>
        </>
    );


    const columns = [
        {
            title: "项目名称/HybridId",
            dataIndex: "project",
            key:"project",
            render: (_, record) => {
                return < ProjectTitle {...record} />;
            }
        },
        {
            title: "离线包灰度比",
            dataIndex: "offRes",
            key:"offRes",
            align: "center",
            render: (text) => {
                return <Gray {...text} />;
            }
        },
        {
            title: "接口预加载灰度比",
            dataIndex: "preloadData",
            key:"preloadData",
            align: "center",
            render: (text) => {
                return <Gray {...text} />;
            }
        },
        {
            title: "创建人 / 修改人 / 修改时间",
            dataIndex: "creater",
            key:"creater",
            align: "center",
            render: (text) => {
                return (
                    <>
                    <div>{text}</div>
                    </>
                );
            }
        },
        {
            title: "项目状态",
            dataIndex: "status",
            key:"status",
            align: "center",
            render: (text) => {
                return (
                    <>
                    <div>{text}</div>
                    </>
                );
            }
        },
        {
            title: "",
            dataIndex: "operate",
            key:"operate",
            align: "center",
            render: (_, {operate}) => {
                return (
                    <div>
                    {operate.map((op) => (
                        <span>{op}</span>
                    ))}
                    </div>
                );
            }
        }
    ];
    const datas = [
        {
            
            projectName: "百亿补贴频道页-预发",
            projectId: "826785123125510144",
            offRes: {
                apple: "50%",
                android: "30%"
            },
            preloadData: {
                apple: "5%",
                android: "3%"
            },
            creater: "wangxiaorui19",
            status: "进行中",
            operate: ["编辑", "配置", "下线", "权限管理"],
        },
        {
            
            projectName: "通天塔新",
            projectId: "749650717872455680",
            offRes: {
                apple: "100%",
                android: "90%"
            },
            preloadData: {
                apple: "15%",
                android: "30%"
            },
            creater: "mabaoyan",
            status: "待发布",
            operate: ["编辑", "配置", "下线", "权限管理"],
        }
    ];
    return (
        <div className="project-container">
            <div>
                <Header />
            </div>
            <div>
                <Table columns={columns} dataSource={datas} />
            </div>
            
        </div>
    );
};