Shader "Custom/RadialProgressRing"
{
    Properties
    {
        [PerRendererData] _MainTex ("Ring Shape (alpha)", 2D) = "white" {}
        _FillAmount ("Fill Amount", Range(0,1)) = 0
        _Started ("Started (0/1)", Float) = 1
        _ColorDone ("Color Done (verde)", Color) = (0.145, 0.514, 0.267, 1)
        _ColorPending ("Color Pending (amarillo)", Color) = (0.984, 0.808, 0.078, 1)
        _ColorNotStarted ("Color Not Started (rojo)", Color) = (0.788, 0.204, 0.329, 1)
        _AngleOffset ("Angle Offset (0..1)", Range(0,1)) = 0
    }

    SubShader
    {
        Tags
        {
            "Queue" = "Transparent"
            "RenderType" = "Transparent"
            "IgnoreProjector" = "True"
            "PreviewType" = "Plane"
            "CanUseSpriteAtlas" = "True"
        }

        Cull Off
        Lighting Off
        ZWrite Off
        Blend SrcAlpha OneMinusSrcAlpha

        Pass
        {
            CGPROGRAM
            #pragma vertex vert
            #pragma fragment frag
            #include "UnityCG.cginc"

            struct appdata
            {
                float4 vertex : POSITION;
                float2 uv : TEXCOORD0;
                float4 color : COLOR;
            };

            struct v2f
            {
                float4 pos : SV_POSITION;
                float2 uv : TEXCOORD0;
                float4 color : COLOR;
            };

            sampler2D _MainTex;
            float4 _MainTex_ST;
            float _FillAmount;
            float _Started;
            float _AngleOffset;
            fixed4 _ColorDone;
            fixed4 _ColorPending;
            fixed4 _ColorNotStarted;

            v2f vert (appdata v)
            {
                v2f o;
                o.pos = UnityObjectToClipPos(v.vertex);
                o.uv = TRANSFORM_TEX(v.uv, _MainTex);
                o.color = v.color;
                return o;
            }

            fixed4 frag (v2f i) : SV_Target
            {
                fixed4 tex = tex2D(_MainTex, i.uv);

                // Angulo alrededor del centro del sprite: 0 arriba, avanzando en sentido horario
                // (tal como se ve en el mapa, considerando el volteo del sprite), normalizado 0..1.
                float2 d = i.uv - 0.5;
                float ang = atan2(-d.x, d.y) / 6.28318530718;
                ang = frac(ang + 1.0 - _AngleOffset);

                fixed4 col;
                if (_Started < 0.5)
                {
                    col = _ColorNotStarted;
                }
                else
                {
                    col = (ang <= _FillAmount) ? _ColorDone : _ColorPending;
                }

                col.a *= tex.a * i.color.a;
                return col;
            }
            ENDCG
        }
    }

    Fallback "Sprites/Default"
}
