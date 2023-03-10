using Plotly
function makePlot(numOfPlots, plotStep, solutionMatrix, dataVec, intervalVec, isQuasi::Bool = false)
    ρ = dataVec[1]
    c = dataVec[2]
    L = dataVec[3]
    timeEnd = dataVec[4]
    σ = 0.0
    α = 0.0
    β = 0.0
    γ = 0.0
    M = 0
    titleText = ""
    numOfXIntervals = Int(intervalVec[1])
    numOfTIntervals = Int(intervalVec[2])

    h = L / numOfXIntervals
    τ = timeEnd / numOfTIntervals    
    if  isQuasi == false
        σ = dataVec[5]
        titleText = "ρ = $ρ, c = $c, σ = $σ      x ∈ [0, $L], t ∈ [0, $timeEnd]      h = $h, τ = $τ"
    else
        α = dataVec[5]
        β = dataVec[6]
        γ = dataVec[7]
        M = dataVec[8]    
        titleText = "ρ = $ρ, c = $c, α = $α, β = $β, γ = $γ, M = $M      x ∈ [0, $L], t ∈ [0, $timeEnd]      h = $h, τ = $τ"
    end
    
    layout = Layout(
        font_family = "Time New Roman",
        font_color = "black",
        title = attr(
            paper_bgcolor = "red",
            text = titleText,
            font_family = "Times New Roman",
            font_color = "black",
            font_size = 20,
            autosize = false,
        ),
        legend = attr(
            font = attr(
                size = 16
            ) 
        ),
        paper_bgcolor = "white",
        plot_bgcolor = "white",
        coloraxis = attr(
        outlinecolor = "black"  
        ),
        height = 600,
        width = 1000,
        xaxis = attr(
            color = "black",
            gridcolor = "black",
            gridwidth = 1,
            zerolinecolor = "black",
            zerolinewidth = 3,
            linecolor = "black",
            linewidth = 3,
            tickfont = attr(
                size = 15
            ),
            title = attr(
                text = "x",
                font_family = "Times New Roman",
                font_color = "black",
                font_size = 20,
            )
        ),
        yaxis = attr(
            gridcolor = "black",
            exponentformat = "power",
            gridwidth = 1,
            zerolinecolor = "black",
            tickfont = attr(
                size = 15
            ),
            title = attr(
                text = "T",
                font_family = "Times New Roman",
                font_color = "black",
                font_size = 20,
            )
        )
    );
    lineAttr = attr(
        width = 2
    );
    markerAttr = attr(
        showline = true, 
        line_width = 1
    )
    pl = plot(
        [scatter(name = "$((k - 1) * τ)", x = [i * h for i in 0 : numOfXIntervals], y = [solutionMatrix[k, i] for i in 1 : numOfXIntervals + 1], mode = "lines+markers", line = lineAttr, marker = markerAttr)
        for k in 1 : plotStep : numOfPlots],
    layout
    )
    return pl
end