import React, { useState } from "react";
import { observer } from "mobx-react-lite";
import { useHistory } from "react-router-dom";
// import "./style.scss";
import "./index.scss";
import { navs } from "../../routers/navs";
import logo from './hybrid-logo.svg';
import Marquee from "react-fast-marquee";

const Header = () => {
    const history = useHistory();
    const [focus, setFocus] = useState("main");

    const clickNavTab = (e, item) => {
        setFocus(item.key);
        history.push(item.path);
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
            <Marquee pauseOnHover gradient={false} gradientColor={[255, 255, 25]}>
                我是公告
            </Marquee>
        );
    }

    return (
        <div>
            <div className="header">
                <img className="header-logo" src={logo}></img>
                <div className="header-router-container">
                    <Tabs/>
                </div>
                <div className="header-notice-container">
                    <Notice />
                </div>
            </div>
            <div className="header-placement"></div>
        </div>
        
        
    );
    
};

export default observer(Header);