import React, { useState } from "react";
import { observer } from "mobx-react-lite";
import { useHistory } from "react-router-dom";
// import "./style.scss";
import "./index.scss";
import { navs } from "../../routers/navs";
import logo from './hybrid-logo.svg';
import Marquee from "react-fast-marquee";
import { SoundOutlined } from "@ant-design/icons"; 
import { notification, Select, Dropdown, Button } from 'antd'; 

const Header = () => {
    const history = useHistory();
    const [focus, setFocus] = useState("main");

    const clickNavTab = (e, item) => {
        setFocus(item.key);
        history.push(item.path);
    };

    const openNotification = (title, body) => {
        notification.open({
          message: title,
          description: body,
          onClick: () => {
            console.log('Notification Clicked!');
          },
        });
      };

    const Tabs = () => {
        return (
            <>
            {
                navs.map((item) => (
                    <div key={item.key} 
                    className={`header-router-navlink ${focus === item.key && 'nav-active'}`}
                    onClick={(e) => {clickNavTab(e, item)}}>
                        <span className="header-text">{item.name}</span>
                    </div>
                ))
            }
            </>
        );
    };

    const Notice = () => {
        return (
            <>
            <SoundOutlined className="header-notice-container-SoundOutlined" />
            <Marquee pauseOnHover gradient={false} gradientColor={[255, 255, 25]}>
                我是公告
            </Marquee>
            </>
        );
    };

    const APPSelector = () => {
        return (
            <>
            <Select
            defaultValue="jd"
            style={{ width: 120 }}
            onChange={(e) => {
                console.log(`选择了${e}`);
            }}
            options={[
                { value: 'jd', label: '京东主站' },
                { value: 'yhd', label: '一号店' },
                { value: 'jx', label: '京喜' },
                { value: 'jdjk', label: '京东健康' },
            ]}/>
            </>
        );
    };

    const UserAccount = () => {
        const items = [
            {
              key: '1',
              label: (
                <Button type="text" onClick={(e) => {
                    console.log('个人资料');
                }}>个人资料</Button> 
              )
            },
            {
              key: '2',
              label: (
                <Button type="text" onClick={(e) => {
                    console.log('退出登录');
                }}>退出登录</Button>  
              )
            }
          ];
          const onSelect = (item, key) => {
            console.log(item + key);
          };
        return (
            <>
             <Dropdown menu={{items}} arrow >
                <a className="header-userAccount-container-menu" onClick={(e) => e.preventDefault()}>
                    wangxiaorui19
                </a>
            </Dropdown>
            </>
            
        );
    };

    return (
        <div>
            <div className="header">
                <img className="header-logo" src={logo}></img>
                <div className="header-router-container">
                    <Tabs/>
                </div>
                <div className="header-notice-container" onClick={(e) => {
                    console.log('点击了公告');
                    openNotification('公告', '我是公告内容');
                }}>
                    <Notice />
                </div>
                <div className="header-right-container">
                    <div className="header-appselector-container">
                        <APPSelector />
                    </div>
                    <div className="header-userAccount-container">
                        <UserAccount />
                    </div>
                </div>
            </div>
            <div className="header-placement"></div>
        </div>
        
        
    );
    
};

export default observer(Header);