import React from "react";
import { observer } from "mobx-react";
import { Table, Button, message, Switch } from "antd";
import { CopyOutlined } from "@ant-design/icons";
import { MobXProviderContext } from "mobx-react";
import "./projectTable.scss";

const ProjectTable = () => {
    const {projects} = React.useContext(MobXProviderContext);

    const operateFunc = (opeIdx, rowIndex) => {
        const data = projects.list[rowIndex];
        switch (opeIdx) {
            case 0: {
                console.log(`编辑操作：${data.projectName}`);
            }
            break;
            case 1: {
                console.log(`配置操作：${data.projectName}`);
            }
            break;
            case 2: {
                console.log(`查看操作：${data.projectName}`);
            }
            break;
            case 3: {
                console.log(`权限管理操作：${data.projectName}`);
            }
            break;
            default:
                console.log("操作出错");
        }
    };

    const ProjectTitle = ({projectName, projectId}) => {
        const [messageApi, contextHolder] = message.useMessage();
        return (
            <>
            {contextHolder}
            <div>{projectName}</div>
            <div className="projectTitle-idAera-container">
                <div className="projectTitle-idAera-id">{projectId}</div>
                <div className="projectTitle-idAera-copyicon"> 
                    <Button type="text" icon={<CopyOutlined />} onClick={async (e) => {
                        try {
                            await navigator.clipboard.writeText(projectId);
                            messageApi.open({
                                type: 'success',
                                content: '复制成功！',
                              });
                          } catch (err) {
                            console.error('Failed to copy: ', err);
                          }
                    }}></Button>
                </div>
            </div>
        </>
        );
    };

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
            render: (_, {offRes}) => {
                return <Gray {...offRes} />;
            }
        },
        {
            title: "接口预加载灰度比",
            dataIndex: "preloadData",
            key:"preloadData",
            align: "center",
            render: (_, {preloadData}) => {
                return <Gray {...preloadData} />;
            }
        },
        {
            title: "创建人 / 修改人 / 修改时间",
            dataIndex: "creater",
            key:"creater",
            align: "center",
            render: (_, {creater}) => {
                return (
                    <>
                    <div >
                        <div >
                        {creater}
                        </div>
                    </div>
                    </>
                );
            }
        },
        {
            title: "项目状态",
            dataIndex: "status",
            key:"status",
            align: "center",
            render: (_, {status}) => {
                return (
                    <>
                    <div className="projectStatus-container">
                        <div className="projectStatus-container-item">
                        {status}
                        </div>
                    </div>
                    </>
                );
            }
        },
        {
            title: "",
            dataIndex: "operate",
            key:"operate",
            align: "center",
            render: (_, {operate}, index) => {
                return (
                    <div className="project-operate-container">
                    {operate.map((op, idx) => (
                        <div className="project-operate-container-item" onClick={()=>{
                            operateFunc(idx, index);
                        }}>{op}</div>
                    ))}
                    </div>
                );
            }
        }
    ];
    console.log(`projects.list: ${typeof projects.list[0]}`);
    return (<Table columns={columns} dataSource={projects.list} />);
};

export default observer(ProjectTable);