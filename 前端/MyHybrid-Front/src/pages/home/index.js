import React from "react";
import "./style.scss";

export default () => {
    return (
        <div className="container">
            {/* <h1>Home</h1>
            <div className="wrapper">
                <div className="box1">box1</div>
                <div className="box2">box2</div>
                <div className="box3">box3</div>
            </div> */}
            <h1>Basic document flow</h1>
            <div className="session">
            {/* <div className="float">Float Box</div> */}
            <p>I am a basic block level element. My adjacent block level elements sit on new lines below me.</p>

            <p className="positioned">By default we span 100% of the width of our parent element, and we are as tall as our child content. Our total width and height is our content + padding + border width/height.</p>

            <p  className="positioned2">We are separated by our margins. Because of margin collapsing, we are separated by the width of one of our margins, not both.</p>

            <p>inline elements <span>like this one</span> and <span>this one</span> sit on the same line as one another, and adjacent text nodes, if there is space on the same line. Overflowing inline elements will <span>wrap onto a new line if possible (like this one containing text)</span>, or just go on to a new line if not, much like this image will do: <img src="/en-US/docs/Learn/CSS/CSS_layout/Normal_Flow/long.jpg" alt="snippet of cloth" /></p>

            </div>
            
        </div>
    );
};